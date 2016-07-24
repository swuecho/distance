use v5.18;
use MCE::Grep;

sub hamming_distance {
    my ($a, $b, $limit) = @_;
    my $len = length $a;
    if ($len != length $b) {
        return 0
    }
    my $mismatch =0;
    for (my $i=0; $i<$len; $i++) {
        if (substr($a, $i, 1) ne substr($b, $i, 1)) {
            $mismatch++;
        }
        return 0 if $mismatch > $limit
    }
    return 1
}

sub select_item {
    my ($item, $csf_cdr3) = @_;
    my @F = split ',';
    my $pb_cdr3 = $F[3];
    return hamming_distance($csf_cdr3, $pb_cdr3, 3)
}

sub process_file {
    my $csf_cdr3 = shift;
    my $pb_cdr3_all = shift;

my $filename = 'result/' . $csf_cdr3 . '.csv';

my @selected = mce_grep { select_item($_, $csf_cdr3) } @$pb_cdr3_all;

open(my $FH, '>', $filename)
  or die "Could not open file '$filename' $!";
print $FH $_ for @selected;

}

open(my $PB_FH, '<', 'pb_cdr3.csv') or die;
my @pb_cdr3_all = <$PB_FH>;
#main
open(my $CSF_FH, '<', 'csf_cdr3.csv') or die;
while(<$CSF_FH>) {
    my @F = split ',';
    my $csf_cdr3 = $F[3];
    say $.;
    process_file($csf_cdr3, \@pb_cdr3_all);
}

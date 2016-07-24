use v5.18;;
sub hd {
       return ($_[0] ^ $_[1]) =~ tr/\001-\255//;
}

sub hamming_distance {
    my ($a, $b) = @_;
    my $len = length $a;
    if ($len != length $b) {
        return 0
    }
    my $mismatch =0;
    for (my $i=0; $i<$len; $i++) {
        if (substr($a, $i, 1) ne substr($b, $i, 1)) {
            $mismatch++;
        }
    }
    return $mismatch:
}

open my $FH, "<", 'csf_cdr3.csv';
my @all_cdr3 =  map  {  (split ',' , $_)[2] } <$FH>
say for @all_cdr3;

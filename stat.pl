use v5.18;



sub check_file {
    my $filename = shift;
    my $filepath = './result/' . $filename;
    open(my $FH, '<', $filepath) or die;
    my $line_count = 0;
    my $include_3421_3289 = 0;
    while(<$FH>){
        my @F = split ',';
        my $subset = $F[5];
        $line_count++;
        if ($subset=~/^(?:3421|3289)/) {
            $include_3421_3289 = 1;
        }
    }
    $filename = (split '\.', $filename)[0];
    return join ',',($line_count, $include_3421_3289, $filename)

}

opendir(my $DIR, "./result") or die;

while (my $file = readdir $DIR) {
    if ($file eq '.' or $file eq '..') {
         next;
    }
    say check_file($file);
}


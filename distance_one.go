package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strings"
)

// copied from
// Hamming computes the Hamming distance between two equal-length strings.
// This is the number of times the two strings differ between characters at
// the same index. This implementation is based off of the algorithm
// description found at http://en.wikipedia.org/wiki/Hamming_distance.
func hamming_limit(s1 string, s2 string, limit int) bool {
	// index by code point, not byte
	r1 := []rune(s1)
	r2 := []rune(s2)

	if len(r1) != len(r2) {
		return false
	}
	distance := 0
	for i, v := range r1 {
		if r2[i] != v {
			distance += 1
		}
		if distance > limit {
			return false
		}
	}
	return true
}

func select_item(item string, csf_cdr3 string) bool {
	pb_cdr3 := strings.Split(item, ",")[3]
	return hamming_limit(csf_cdr3, pb_cdr3, 2)
}

func process_file(csf_cdr3 string) {
	//filename := folder + "/" + csf_cdr3 + ".csv"
	file, err := os.Open("pb_cdr3.csv")
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		line := scanner.Text()
		if select_item(line, csf_cdr3) {
			fmt.Println(line)
		}
	}
	if err := scanner.Err(); err != nil {
		log.Fatal(err)
	}

}

func main() {
	csf_cdr3 := "CARGLDYW"
	process_file(csf_cdr3)
}

/*

sub process_file {
    my $csf_cdr3 = shift;

my $filename = 'denge/' . $csf_cdr3 . '.csv';

open(my $FH, '>', $filename)
  or die "Could not open file '$filename' $!";

open(my $PB_FH, '<', 'pb_cdr3.csv') or die;

my @selected = mce_grep { select_item($_, $csf_cdr3) } $PB_FH;

print $FH $_ for @selected;

}

my $csf_cdr3 = 'CARLDYYYYYGMDL';
process_file($csf_cdr3);
$csf_cdr3 = 'CARLDYYYYYGMD';
process_file($csf_cdr3);
$csf_cdr3 = 'CARLDYYYYYGM';
process_file($csf_cdr3);
$csf_cdr3 = 'CARLDYYYYYG';
process_file($csf_cdr3);
*/

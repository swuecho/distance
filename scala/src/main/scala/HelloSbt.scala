object Hm {
  import java.nio.file._

def hamming_distance(a: String, b: String, limit: Int) : Boolean = {
    val len = a.length
    if (len != b.length) {
        return false 
    }
    var mismatch =0
    for (idx <- 0 until len) {
        if (a.charAt(idx) != b.charAt(idx)) {
            mismatch +=1
        }
        if (mismatch > limit) {
            return false 
        }
    }
    return true
}

def cdr3_from_line(line: String) : String = {
    return  line.split(",")(3)
}

def csf_cdr3_vs_pb_cdr3(csf_cdr3: String, pb_cdr3s: List[String]): Unit = {
  val cdr3 = pb_cdr3s.filter(x => hamming_distance(cdr3_from_line(x), csf_cdr3, 2)) 
   Files.write(Paths.get("/home/hwu/dev/distance/result_scala/" + csf_cdr3 + ".csv"), cdr3.mkString("\n").getBytes())


}

}


object HelloSbt extends App {

    val csf_file = "/home/hwu/dev/distance/data/raw/csf_cdr3.csv"
    val csf_lines = io.Source.fromFile(csf_file).getLines
    val pb_file = "/home/hwu/dev/distance/data/raw/pb_cdr3.csv"
    val pb_lines = io.Source.fromFile(pb_file).getLines.toList
    csf_lines.toList.par.foreach( x => Hm.csf_cdr3_vs_pb_cdr3(Hm.cdr3_from_line(x),pb_lines))
}

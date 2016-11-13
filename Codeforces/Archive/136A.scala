object A136 {
	def main(args: Array[String]) = {
		val params = 
		val n = readInt
		val a = List(readLine.split(" ") map Integer.parseInt)
		var res: List[Int] = Nil
		for (i <- 0 to n - 1)
			res = res(:a(i)) :: List(i) :: res[a(i) + 1:]
		res.foreach(i => print(i + " "))
	}
}
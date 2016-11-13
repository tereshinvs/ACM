object A {
	def main(args: Array[String]) = {
		val s = readLine split " "
		val n = Integer parseInt s(0)
		val m = Integer parseInt s(1)
		val k = Integer parseInt s(2)
		val a = readLine split " " map(x => Integer parseInt x) toList;
		for (x <- a.sorted)
			println(x)
	}
}
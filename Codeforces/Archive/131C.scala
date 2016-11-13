object C131 {
	def fact(t: Int): BigInt = if (t <= 1) BigInt(1) else t * fact(t - 1)
	implicit def implfact(t: Int) = new { def ! = fact(t)}

	def c(n: Int, k: Int): BigInt = (n!)/((k!) * ((n - k)!))

	def main(args: Array[String]) {
		val s = readLine.split(" ")
		val n = Integer.parseInt(s(0))
		val m = Integer.parseInt(s(1))
		val t = Integer.parseInt(s(2))
		var res = BigInt(0)
		for (i <- 4 to n)
			for (j <- 1 to m)
				if (i + j == t)
					res += c(n, i) * c(m, j)
		println(res)
	}
}
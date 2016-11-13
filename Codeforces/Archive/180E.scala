object E180 {
	def main(args: Array[String]): Unit = {
		val par1 = readLine.split(" ") map Integer.parseInt
		val n = par1(0)
		val m = par1(1)
		val k = par1(2)
		val alr = new Array[Int](m)
		val cl = new Array[List[Int]](m)
		val par2 = readLine.split(" ") map Integer.parseInt
		for (i <- 0 to n - 1) {
			val x = par2(i) - 1
			if (cl(x) == null)
				cl(x) = List()
			cl(x) = cl(x) ::: List(i - alr(x))
			alr(x) += 1
		}
		var res = 0
		for (clr <- cl if clr != null) {
			var left = 0
			for (i <- 0 to clr.length - 1) {
				while (clr(i) - clr(left) > k)
					left += 1
				res = math max(res, i - left + 1)
			}
		}
		println(res)
	}
}
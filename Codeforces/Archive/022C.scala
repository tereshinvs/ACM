object C022 {
	def main(args: Array[String]) {
		val n = readInt
		var m = readInt
		val v = readInt - 1
		if (m + 1 < n || (n % 2 == 1 && (n % 2) * (n % 2 - 1) < m)
			|| (n % 2 == 0 && (n % 2) * (n % 2 - 1) / 2 + (n % 2) * (n % 2 + 1) / 2 < m)) {
			print(-1)
			sys.exit(0)
		}
		var temp: List = Nil
		var k = 0
		for (i <- 0 to n - 1) {
			k = i + 1
			if (i == v)
				continue
			temp = temp ::: List(i)
		}
	}
}
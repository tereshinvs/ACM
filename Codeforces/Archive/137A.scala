object A137 {
	def main(args: Array[String]) {
		val s: String = readLine
		var res: Int = 0
		var curc: Char = '?'
		var curval: Int = 5
		for (c <- s)
			if (c == curc && curval < 5)
				curval += 1
			else {
				res += 1
				curval = 1
				curc = c
			}
		println(res)
	}
}
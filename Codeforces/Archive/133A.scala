object A133 {
	def main(args: Array[String]) {
		val list = List('H', 'Q', '9')
		var flag = false
		for (c <- readLine.toCharArray)
			flag ||= list.exists(c == _)
		print(if (flag) "YES" else "NO")
	}
}
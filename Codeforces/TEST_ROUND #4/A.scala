object A {
	def main(args: Array[String]) {
		val s = readLine
		var curw = ""
		for (c <- s) {
			if (c == ' ' && curw != "")
				print(curw + " ")
			else if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
				curw = 
		}
	}
}
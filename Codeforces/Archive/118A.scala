object A118 {
	def main(args: Array[String]) = {
		val vow = List('a', 'e', 'i', 'u', 'y', 'o')
		for (c <- readLine.toLowerCase.toCharArray)
			if (!vow.exists(c == _))
				print("." + c)
	}
}
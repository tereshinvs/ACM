object E131 {
	def main(args: Array[String]) {
		val n = readInt
		var a: List[Ferzin] = Nil
		for (i <- 0 to n - 1)
			a = a ::: List(new Ferzin(readLine.split(" "), i))
		for (cmp <- comparators) {
			a = a.sort(cmp)
			for (i <- 0 to n - 1) {
			}
		}
	}

	def lowerBound(a: List[Ferzin], n: Int, cmp: (Ferzin, Ferzin) => Boolean): Int = {
		
	}

	def upperBound(a: List[Ferzin], n: Int, cmp: (Ferzin, Ferzin) => Boolean): Int = {
	}

	class Ferzin(crd: Array[String], numc: Int) {
		val x = Integer.parseInt(crd(0))
		val y = Integer.parseInt(crd(1))
		val num = numc
	}

	val comparators: List[(Ferzin, Ferzin) => Boolean] = List(
		(t1: Ferzin, t2: Ferzin) => {
			if (t1.y < t2.y) true
			if (t1.y > t2.y) false
			if (t1.x < t2.x) true
			else false
		},

		(t1: Ferzin, t2: Ferzin) => {
			if (t1.x < t2.x) true
			if (t1.x > t2.x) false
			if (t1.y < t2.y) true
			else false
		},

		(t1: Ferzin, t2: Ferzin) => {
			if (t1.x + t1.y < t2.x + t2.y) true
			if (t1.x + t1.y > t2.x + t2.y) false
			if (t1.x - t1.y < t1.x - t2.y) true
			else false
		},

		(t1: Ferzin, t2: Ferzin) => {
			if (t1.x - t1.y < t2.x - t2.y) true
			if (t1.x - t1.y > t2.x - t2.y) false
			if (t1.x + t1.y < t1.x + t2.y) true
			else false
		}
	)
}
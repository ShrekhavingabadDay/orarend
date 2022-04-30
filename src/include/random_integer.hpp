#ifndef RAND_INT
#define RAND_INT

class RandInt {

	private:
		const unsigned int range;

	public:
		RandInt(unsigned int range);
		unsigned int gen(void) const;
};

#endif

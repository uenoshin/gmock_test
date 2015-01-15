
extern int (*exAPI)(int);

class Target  {
	public:
		virtual ~Target(){}
		virtual int Func(int n){
			n = exAPI(n);
			return n;
		}
};

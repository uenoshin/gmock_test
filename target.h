
extern int (*exAPI)(int);

#if 0
class exAPIIF_TMP {
 public:
  virtual int laexAPI(int) = 0;
};

class exAPIIF : public exAPIIF_TMP {
 public:
  virtual int laexAPI(int a) {
    return exAPI(a);
  }
};
#endif

class Target {
	public:
		virtual ~Target(){}
		virtual int Func(int n)=0;
};

class Lapper : public Target {
	public:
		virtual ~Lapper(){}
		virtual int Func(int n){
			n = exAPI(n);
			return n;
		}
};

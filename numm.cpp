#include "spck.h"
using namespace std;//   here is where the comments go
SpellCheck::SpellCheck(string Dicpath,string frequPath){//   things get complex after his
	DictionaryLocation = Dicpath;// check  the
	FrequencyListLoc = frequPath;
	Dictionary k(DictionaryLocation);
	oxy = k;
}

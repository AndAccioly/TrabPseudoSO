#ifndef GERRECURSOS_H
#define GERRECURSOS_H

using namespace std;

class GerRecursos{

private:

    GerRecursos();

public:

    static GerRecursos& instance(){
      static GerRecursos instance;
      return instance;
    }
    
};

#endif // GERRECURSOS_H

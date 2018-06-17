#include <functional>
#include <iostream>
#include <map>

template < typename Ret, typename... Args >
class VarFuncHolder {
public:
    // default constructor
    VarFuncHolder() {} 
    // constructor with parameters
    //VarFuncHolder(const std::string& name, std::function< Ret( Args... ) > Func) {
    //    Assign(name, Func);
    //}
    // Execute the function object stored at 'name', with values passed as Pack
    Ret Execute ( const std::string& name, Args... Pack ) {
        return m_Funcs[name]( Pack... );
    }
    // Assign passed function object Func to key represented by name
    void Assign( const std::string& name, std::function< Ret( Args... ) > Func ) {
        m_Funcs[name] = Func;
    }
private:
    static std::map< std::string, std::function< Ret( Args... ) > > m_Funcs;
};
 
// Definition for m_Funcs
template< typename Ret, typename... Args >
std::map< std::string, std::function< Ret( Args... ) > > VarFuncHolder< Ret, Args... >::m_Funcs;
 
int main()
{
    auto functor1 = []( int a, int b )->int{ return a - b; };
 
    auto functor2 = []( double a, double b, double c )->double{ return ( a + b ) / c; };
 
    // Create an instance, add function object to static m_Funcs map
    VarFuncHolder< int, int, int >varFunc1;
    varFunc1.Assign( "functor1", functor1 );
    std::cout << "functor1 returns : " << varFunc1.Execute( "functor1", 10, 5 ) << "\n";
 
    // Create another instance add a function object with different signature to static m_Funcs map
    VarFuncHolder< double, double, double, double >varFunc2;
    varFunc2.Assign( "functor2", functor2 );
    std::cout << "functor2 returns : " << varFunc2.Execute( "functor2", 5.0, 5.0, 1.5 ) << "\n";
}

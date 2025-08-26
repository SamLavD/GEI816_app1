# include < string >
# include < iostream >
# include < fstream >
using namespace std ;

# include " NumCpp . hpp "

class ConvBase {
public :

string src ;
string ext ;

ConvBase ( string src ) {
this - > src = src ;
this - > ext = ". oops . txt " ;
}

nc :: NdArray < int > lireSrc ( void ){
return nc :: fromfile < int >( this -> src , '\n ');
}

string newName ( void ) {
return this - > src + this -> ext ;
}
// pure virtual --> requires overload
virtual void conv ( void ) = 0;
};

class ConvBin : public ConvBase
{
public :
ConvBin ( string src ) : ConvBase ( src ) {
    this - > ext = ". bin . txt ";
}

void conv ( void ) {
    nc :: NdArray < int > values = this - > lireSrc () ;
    ofstream myfile ;
    myfile . open ( this -> newName () ) ;

    for ( int x = 0; x < values . size () ; x ++) {
    myfile << std :: bitset <10 >( values [ x ])
    << endl ;
    }
    myfile . close () ;
    }
};

class ConvHexShift : public ConvBase
{
public :
ConvHexShift ( string src ) : ConvBase ( src ) {
    this -> ext = ". hex . txt ";
}

nc :: NdArray < int > lireSrc ( void ){
    nc :: NdArray < int > temp = ConvBase :: lireSrc () ;
    temp *= 16;
    return temp ;
}

void conv ( void ) {
    nc :: NdArray < int > values = this - > lireSrc () ;
    ofstream myfile ;
    myfile . open ( this -> newName () ) ;
    for ( int x = 0; x < values . size () ; x ++) {
    myfile << std :: hex << values [ x] << endl ;
    }
    myfile . close () ;
}
};

int main ( void ) {
ConvBin * TestBin = new ConvBin (" seq . txt " );
TestBin -> conv () ;
ConvHexShift * TestHex = new ConvHexShift (" seq . txt ");
TestHex -> conv () ;
return 0;
}
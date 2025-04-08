// CLASS IMPLEMENTED: Statistician (see stats.h for documentation)
#include <assert.h>   // Provides assert
#include <ctype.h>    // Provides isspace
#include <iostream> // Provides istream class
#include "stats.h"

using namespace std;

Statistician::Statistician( )
{
    reset( );
}

void Statistician::next(double r)
{
    total += r;
    count++;
    if ((count == 1) || (r < tinyest))
        tinyest = r;
    if ((count == 1) || (r > largest))
        largest = r;
}

void Statistician::reset( )
{
    count = 0;
    total = 0;
}

double Statistician::mean( ) const
// Library facilities used: assert.h
{
    assert(length() > 0);
    return total/count;
}

double Statistician::minimum( ) const
// Library facilities used: assert.h
{
    assert(length( ) > 0);
    return tinyest;
}

double Statistician::maximum( ) const
// Library facilities used: assert.h
{
    assert(length( ) > 0);
    return largest;
}



Statistician operator +(const Statistician& s1, const Statistician& s2)
{
    Statistician answer;

    if (s1.count == 0)
	answer = s2;
    else if (s2.count == 0)
	answer = s1;
    else
    {
	answer.count = s1.count + s2.count;
	answer.total = s1.total + s2.total;
	answer.tinyest = (s1.tinyest <= s2.tinyest) ? s1.tinyest : s2.tinyest;
	answer.largest = (s1.largest >= s2.largest) ? s1.largest : s2.largest;
    }
    return answer;
}



Statistician operator *(double scale, const Statistician& p)
{
    Statistician answer;

    answer.count = p.count;
    answer.total = scale * p.total;
    if (scale >= 0)
    {
	answer.tinyest = scale * p.tinyest;
	answer.largest = scale * p.largest;
    }
    else
    {
	answer.tinyest = scale * p.largest;
	answer.largest = scale * p.tinyest;
    }
    return answer;
}

bool operator ==(const Statistician& s1, const Statistician& s2)
{
    if ((s1.length( ) == 0) || (s2.length( ) == 0))
        return (s1.length( ) == 0) && (s2.length( ) == 0);
    else return (s1.length( ) == s2.length( ))
            &&  (s1.mean( ) == s2.mean( ))
	    &&  (s1.minimum( ) == s2.minimum( ))
	    &&  (s1.maximum( ) == s2.maximum( ))
	    &&  (s1.sum( ) == s2.sum( ));
}


istream& operator >>(istream& ins, Statistician& target)
{
    double user_input;

    while (ins && (ins.peek( ) != ';'))
    {
	if (isspace(ins.peek( )))
	    ins.ignore( );
	else
	{
	    ins >> user_input;
	    target.next(user_input);
	}
    }
    ins.ignore( );

    return ins;
}




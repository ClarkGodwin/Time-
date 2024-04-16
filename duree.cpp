#include <iostream>

using namespace std;

class duree
{
   public:
   duree (int heures=0, int minutes=0, int secondes=0);
   duree(duree const& a);
   bool egal(duree const& b)const;
   duree operator+=(duree const& a);
   duree operator-=(duree const& a);
   bool operator>(duree const& b);
   bool operator<(duree const& b);
   bool operator>=(duree const& b);
   bool operator<=(duree const& b);
   void afficher(ostream& flux) const;
   duree adjust();
   duree in(istream& flux);
   
   private:
   int m_heures;
   int m_minutes;
   int m_secondes;
};

bool operator==(duree const& a,duree const& b);

duree operator+(duree const& a,duree const& b);

duree operator-(duree const& a,duree const& b);

ostream& operator<<(ostream&flux, duree const& a);

duree operator>>(istream&flux, duree& a);

int main()
{
	duree d1(3),d2(3,30);
	cout<<"Enter d1: "<<endl;
	cin>>d1;
	cout<<"Enter d2: "<<endl;
	cin>>d2;
	cout<<d1<<" + "<<d2<<" = "<<d1+d2<<endl;
	cout<<d1<<" - "<<d2<<" = "<<d1-d2<<endl;
	return 0;
}

duree duree::adjust()
{
	int sum(m_heures*3600+m_minutes*60+m_secondes);
	m_heures=sum/3600;
	sum%=3600;
	m_minutes=sum/60;
	sum%=60;
	m_secondes=sum;
	return *this;
}

duree::duree(int heures,int minutes, int secondes):m_heures(heures), m_minutes(minutes), m_secondes(secondes)
{
	adjust();
}

duree::duree(duree const& a):m_heures(a.m_heures), m_minutes(a.m_minutes), m_secondes(a.m_secondes){}

bool duree::egal(duree const& b)const
{
	return (m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes == b.m_secondes);
}

void duree::afficher(ostream& flux) const 
{
	flux<<m_heures<<"h:"<<m_minutes<<"min:"<<m_secondes<<"sec";
}

duree duree::in(istream& flux)
{
	int h,m,s;
	cout<<"h:";
	flux>>h;
	m_heures=h;
	cout<<"min:";
	flux>>m;
	m_minutes=m;
	cout<<"sec:";
	flux>>s;
	m_secondes=s;
	adjust();
	cout<<*this<<endl<<endl;
	return *this;
}

bool operator==(duree const& a, duree const& b)
{
	return a.egal(b);
}

bool duree::operator>=(duree const& b)
{
	return (m_heures*3600+m_minutes*60+m_secondes)>=(b.m_heures*3600+b.m_minutes*60+b.m_secondes);
}

bool duree::operator<=(duree const& b)
{
	return (m_heures*3600+m_minutes*60+m_secondes)<=(b.m_heures*3600+b.m_minutes*60+b.m_secondes);
}

bool duree::operator>(duree const& b)
{
	return (m_heures*3600+m_minutes*60+m_secondes)>(b.m_heures*3600+b.m_minutes*60+b.m_secondes);
}

bool duree::operator<(duree const& b)
{
	return (m_heures*3600+m_minutes*60+m_secondes)<(b.m_heures*3600+b.m_minutes*60+b.m_secondes);
}

duree duree::operator+=(duree const& a)
{
	m_heures+=a.m_heures;
	m_minutes+=a.m_minutes;
	m_secondes+=a.m_secondes;
	adjust();
	return *this;
}

duree duree::operator-=(duree const& a)
{
	if(*this < a)
		cout<<"Error"<<endl<<endl;
	else
	{
		m_heures-=a.m_heures;
		m_minutes-=a.m_minutes;
		m_secondes-=a.m_secondes;
		adjust();
	}
	return *this;
}

duree operator+(duree const& a, duree const& b)
{
	duree c(a);
	c+=b;
	return c;
}

duree operator-(duree const& a, duree const& b)
{
	duree c(a);
	c-=b;
	return c;
}

ostream& operator<<(ostream&flux, duree const& a)
{
	a.afficher(flux);
	return flux;
}

duree operator>>(istream&flux, duree& a)
{
	a.in(flux);
	return a;
}

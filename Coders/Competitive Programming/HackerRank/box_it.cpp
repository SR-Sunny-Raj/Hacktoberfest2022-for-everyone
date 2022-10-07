// Box It!
// question link : https://www.hackerrank.com/challenges/box-it/problem


// box class
class Box{
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box
public:
int l,b,h;

// The class should have the following functions : 

// Constructors: 
 Box(){
   l=0;
   b=0;
   h=0;
 }
 Box(int x ,int y, int z){
   l=x;
   b=y;
   h=z;
 }
 Box(const Box& a){
   l=a.l;
   b=a.b;
   h=a.h;
 }


int getLength(){
  return l;
} // Return box's length
int getBreadth (){
  return b;
} // Return box's breadth
int getHeight (){
  return h;
}  //Return box's height
long long CalculateVolume(){
  return (long long)(l)*b*h;
} // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& x , Box& y);

//Overload operator << as specified
friend ostream &operator<<(std::ostream& out, Box& B);

bool operator<(Box& x){
  if ( l <x.l) {
   return true;
  }
  if(b<x.b && l==x.l){
    return true;
  }
  if(h<x.h && b==x.b && l==x.l ){
  return true;
  }
  return false;
}
};
 ostream&  operator<<(ostream& out, Box& B){
  cout<<B.l<<" "<<B.b <<" "<<B.h;
  return out;
}

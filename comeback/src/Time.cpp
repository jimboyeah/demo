/*
 * C++ supports a second keyword, struct, that can be used to define class types.
 * The struct keyword is inherited from C.
   The only difference between a class defined with the class keyword or
   the struct keyword is the default access level:
   By default, members in a struct are public; those in a class are private.
 */

struct Time{
    //struct member is public by default!
    public:
    //default constructor must offer when other is come.
    Time (int h, int m, int s){
        hours = h;
        minutes = m;
        seconds = s;
    }
    int getTime(){
        return hours*60*60+minutes*60+seconds;
    }
    int setSeconds(int s){
        if(s>59 || s<1) return seconds;
        seconds = s;
        return s;
    }
    int setMinutes(int m){
        if(m>59||m<1) return minutes;
        minutes = m;
        return m;
    }
    int setHours(int h){
        if(h>23 || h<1) return hours;
        hours  = h;
        return h;
    }

    int hours;
    int minutes;
    int seconds;

    //private:
    //here is reserved for private member

}; //a close semicolon must been appended

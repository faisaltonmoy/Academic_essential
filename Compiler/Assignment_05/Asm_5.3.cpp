#include<stdio.h>
#include <string.h>

char str[1000];

int f = 0 , i = 0;
void Term();
void Factor();
void Exp();
void stat();
void isID();
void isNum();
void asgn();
void dscn();
void expn();
void reloop();
void extn();
void extn_con();
void loop_();

int main(){

   gets(str);

   stat();

   if(f == 1 && i == strlen(str)){
      puts("string matched");
   }else{
     puts("string does not matched");
   }

  return 0;
}

//for(a=b;b<c;d=a)if(a==c)c=2
//while(a==b)if(a==c)c=2elsec=3
//if(a+b)c=5
//if(a==b)c=2
//if(a==c)c=2elsec=3
//if(a+b)c=5


void isID(){

    if(str[i] == 'a' || str[i] == 'b' || str[i] == 'c' || str[i] == 'd' || str[i] == 'e'){
        i++;
        f = 1;
        return;
    }else{
       f = 0;
       return;
    }
}

void isNum(){

    if(i == strlen(str)){
        f = 1;
        return;
    }
    if(str[i] >= '0' &&  str[i] <= '9'){
        i++;
        f = 1;
        return;
    }else{
      f = 0;
      return;
    }
}
void Term(){

    Factor();
    if(f == 1 &&  (str[i] == '*' || str[i] == '/')){
         i++;
         Factor();
    }
}
void Exp(){

    Term();
    if(f && str[i] == '+' || str[i] == '-'){
       i++;
       Term();
    }
}

void Factor(){

       isID();
       if(f == 1){
        return;
       }
       isNum();
       if(f == 1){
        return;
       }
     if(str[i] == '('){
       i++;
       f = 1;
       if(f == 1){
         Exp();
       if(f == 1){
         if(str[i] == ')'){
            i++;
            f = 1;
            return;
         }else{
           f = 0;
           return;
         }
       }else{
         f = 0;
         return;
       }
       }else{
         f = 0;
         return;
       }
     }
     f = 0;
     return;
}

void stat(){
    asgn();

    if(f == 1){
        return;
    }
    dscn();
    if(f == 1){
        return;
    }
    loop_();
    if(f == 1){
        return;
    }
    f = 0;
    return;
}

void asgn(){
    isID();

    if(f == 1 && (str[i] == '=')){
        i++;
        f = 1;
        if(f == 1 && i != strlen(str)){
            expn();
        }else{
         f = 0;
         return;
        }
    }else{
      f = 0;
      return;
    }
}
void expn(){
   if(f == 1)
    Exp();
   if(f == 1){
    extn();
   }else{
    f = 1;
    return;
   }
}
void extn(){

    reloop();
    if(f == 1){
     Exp();
    }else{
      f = 1;
      return;
    }
}
void reloop(){

    if((str[i] == '=' && str[i+1] == '=') ||
       (str[i] == '!' && str[i+1] == '=')  || (str[i] == '<' && str[i+1] == '=') ||
        (str[i] == '>' && str[i+1] == '=')){
        i+=2;
        f = 1;
        return;
      }
      else if(str[i] == '<' || str[i] == '>'){
        i++;
        f = 1;
        return;
      }
      else{
        f = 0;
        return;
      }
}

void dscn(){

   if(i == strlen(str)){
    return;
   }
   if(str[i] == 'i' && str[i+1] == 'f' && str[i+2] == '('){
    i += 3;
    f = 1;
     if(f == 1){
      expn();
     if(f == 1){
        if(str[i] == ')'){
            i++;
            f = 1;
         if(f == 1){
          stat();
          if(i == strlen(str)){
            return;
          }
           if(f == 1){
            extn_con();
            return;
           }
           else{
            f = 0;
            return;
          }
         }else{
          f = 0;
          return;
         }
        }
        }
        else{
          f = 0;
          return;
         }

       }else{
        f = 0;
        return;
       }
      }
   f = 0;
   return;
}

void extn_con(){

   if(str[i] == 'e' && str[i+1] == 'l' && str[i+2] == 's' && str[i+3] == 'e'){
      i+=4;
      f = 1;
      if(f == 1){
        stat();
        return;
      }else{
        f = 0;
        return;
      }
   }else{
    f = 0;
    return;
   }
}

void loop_(){

    if(str[i] == 'w' && str[i+1] == 'h' && str[i+2] == 'i' && str[i+3] == 'l' && str[i+4] == 'e' && str[i+5] == '('){
            i += 6;
            f = 1;
            if(f == 1){
                expn();
                if(f == 1){
                     if(str[i] == ')'){
                         i++;
                         f = 1;

                         if(f == 1){
                            stat();
                            return;
                         }else{
                           f = 0 ;
                           return;
                         }
                     }else{
                       f = 0;
                       return;
                     }
                }else{
                  f = 0;
                  return;
                }
            }else{
              f = 0;
              return;
            }
       }

       if(str[i] == 'f' && str[i+1] == 'o' && str[i+2] == 'r' && str[i+3] == '('){
           i += 4;
           f = 1;
           if(f == 1){
             asgn();
              if(f == 1){
                 if(str[i] == ';'){
                    i++;
                    f = 1;
                    if(f == 1){
                        expn();
                        if(f == 1){
                             if(str[i] == ';'){
                             i++;
                             f = 1;
                             if(f == 1){
                                asgn();

                                  if(f == 1){

                                    if(str[i] == ')'){
                                        i++;
                                        f = 1;
                                       if(f == 1){
                                        stat();
                                        return;
                                       }else{
                                         f = 0;
                                         return;
                                       }
                                    }else{
                                      f = 0;
                                      return;
                                    }

                                }else{
                                 f = 0;
                                 return;
                                }
                             }

                             else{
                                f = 0;
                                return;
                             }

                            }
                            else{
                                f = 0;
                                return;
                            }
                        }else{
                          f = 0;
                          return;
                        }
                    }else{
                      f =0;
                      return;
                    }
                 }else{
                  f = 0;
                  return;
                 }
              }else{
               f =0;
               return;
              }
           }else{
             f =0;
             return;
           }

       }

}


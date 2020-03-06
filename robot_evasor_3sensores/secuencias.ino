void secuencias(int D1, int D2, int D3){
if (D2>15){
  adelante();

if(D1<5 && D3<5){
  parar();
  atras();
}
if (5>D2){
    derecha(giro_normal); 
     parar(); 
     adelante();
  }
 if (5>D1){
    izquierda(giro_normal); 
     parar(); 
     adelante();
  } 
}
else{
  parar(); 
  if (D1>D2){
    derecha(giro_normal); 
     parar(); 
     adelante();
  }
 else if (D1<D2){
     izquierda(giro_normal);
       parar(); 
      adelante();
  }
}
}

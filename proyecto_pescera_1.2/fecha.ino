int  menu(int limite) {
  int boton = digitalRead(2);
  x_axis = analogRead(A3);
  x_axis = map(x_axis, 0, 1024, 0, 3);
  y_axis = analogRead(A2);
  y_axis = map(y_axis, 0, 1024, 0, 3);
  if (y_axis == 2) {
    contador++;
    delay(250);
  }
  if (y_axis == 0) {
    contador--;
    delay(250);
  }
  if (contador > limite ) {
    contador = 0;
  }
if( contador < 0){
  contador=limite;
}
  return contador, x_axis, boton;
}

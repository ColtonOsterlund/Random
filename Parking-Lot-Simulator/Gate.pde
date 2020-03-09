class Gate {
  boolean open;
  float fee;
  int numberofspots;
  String feeString;

  Gate(boolean b, float f, int n) {
    open = b;
    fee = f;
    numberofspots = n;
    
  }


  void drawGate() {
    feeString = nfc(fee,2);
    
    //CONNECTION BETWEEN STREETS AND PARKING LOT
    noStroke();
    fill(129, 129, 129);
    rect(1006, 324, 188, 32);
    rect(1006, 1244, 188, 32);
    stroke(255);
    strokeWeight(5);
    line(1006, 330, 1006, 350);
    line(1194, 330, 1194, 350);
    line(1006, 1250, 1006, 1270);
    line(1194, 1250, 1194, 1270);

    //UPPERGATEARM
    stroke(0);
    strokeWeight(10);
    //UPPER ARM
    if (open == true) {
      line(1015, 350, 1020, 470);
      fill(0, 255, 0);
    } else if (open == false) {
      fill(255, 0, 0);
      line(1015, 350, 1182, 350);
    }
    //LOWER ARM
    line(1015, 1250, 1020, 1110);

    //GATEBOXESUPPER
    strokeWeight(5);
    stroke(0);
    fill(255);
    rect(800, 331, 200, 30);
    rect(800, 1219, 200, 30);
    //GATEBOXESLOWER
    fill(0, 102, 255);
    rect(800, 361, 200, 30);
    rect(800, 1249, 200, 30);

    //ARMLIGHTS
    noStroke();  
    if (open)
      fill(0, 255, 0);
    else
      fill(255, 0, 0);
    ellipse(1015, 350, 10, 10);
    ellipse(1015, 1250, 10, 10);

    //GATEWRITTING
    fill(0);
    textSize(25);
    text("ENTRANCE", 835, 356);
    text("EXIT", 875, 1246);
    text("Spaces: " + numberofspots, 835, 387);
    text("Fee = $" + feeString, 835, 1275);
  }
}
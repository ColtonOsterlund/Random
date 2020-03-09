class ControlPanel {
  float NetProfit = 0;
  int TimeElapsed = 0;
  int Customers = 0;
  String NetProfitString;

  void ParkingRatesDisplay() {
    stroke(0);
    fill(204, 255, 153);
    rect(10, 5, 545, 215);
    fill(0);
    textSize(40);
    text("Parking Rates:", 15, 40);
    line(10, 55, 555, 55);
    if (Date.today >= 0 && Date.today <= 5) {
      noStroke();
      fill(153, 255, 204);
      rect(15, 80, 535, 50);
    } else if (Date.today == 6) {
      noStroke();
      fill(153, 255, 204);
      rect(15, 140, 535, 50);
    }
    fill(0);
    text("Mon - Sat : $3.00/Hour", 15, 120);
    text("Sun : $1.50/Hour", 15, 180);
  }

  void PausePlayDisplay() {
    stroke(0);
    fill(204, 255, 153);
    rect(605, 5, 500, 215);
    line(855, 5, 855, 215);
    fill(0, 255, 0);
    ellipse(730, 112, 200, 200);
    fill(0);
    triangle(690, 50, 690, 170, 800, 110);
    fill(255, 0, 0);
    ellipse(980, 112, 200, 200);
    fill(0);
    rect(935, 70, 90, 90);

    if (mouseX > 880 && mouseX < 1080 && mouseY > 12 && mouseY < 212) {
      if (mousePressed)
        for (int x = 0; x >= 0; x++) {
          noLoop();
          if (mouseX > 630 && mouseX < 830 && mouseY > 12 && mouseY < 212) {
            if (mousePressed)
              break;
          }
        }
      loop();
    }
  }

  void SimulationValuesDisplay() {
    NetProfitString = nfc(NetProfit,2);
    
    fill(204, 255, 153);
    rect(1155, 5, 645, 215);
    fill(0);
    textSize(40);
    text("Simulation Values:", 1160, 40);
    stroke(0);
    line(1155, 55, 1800, 55);
    text("Net Profits : $" + NetProfitString, 1160, 95);
    text("Time Elapsed : " + TimeElapsed + " Hours", 1160, 150);
    text("Customers : " + Customers, 1160, 205);
  }

  void DateTimeDisplay() {
    Date.printDate(2190, 30, 35);
    stroke(0);
    if ((Date.hour >= 7 && Date.hour < 12 && Date.before_noon == true) || ((Date.hour <= 6 || Date.hour == 12) && Date.before_noon == false)) {
      fill(0, 255, 255);
      rect(1850, 40, 340, 180);
      image(Sun, 1900, 55, 250, 150);
    } else {
      fill(0);
      rect(1850, 40, 340, 180);
      image(Moon, 1930, 55, 200, 150);
    }
  }
}
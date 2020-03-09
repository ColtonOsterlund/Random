class Car {
  float StartingX;
  float StartingY = 200;
  float CarType;
  float CarSpeed = 10;
  boolean DisplayCar;
  float x = random(0, 4);
  int a = (int) random(0, 2), b = (int) random(0, 3), c = (int) random(0, 5), d = (int) random(0, 2); //CHOOSES RANDOM STALL LOCATION
  int Leave = 0;
  boolean CarInStall = true;
  int LeavingY = 900;
  float MinutesStayed = 0;


  Car(float CT, float SX, boolean DC) {
    CarType = CT;
    StartingX = SX;
    DisplayCar = DC;
  }

  void drawCar() {

    if (DisplayCar == true) {
      if (CarType > 0 && CarType <= 1) {
        image(Lancer, StartingX, StartingY, 175, 150);
        StartingX += CarSpeed;
      } else if (CarType > 1 && CarType <= 2) {
        image(BMW, StartingX, StartingY, 200, 150);
        StartingX += CarSpeed;
      } else {
        image(Pontiac, StartingX, StartingY, 175, 150);
        StartingX += CarSpeed;
      }

      if (StartingX >= (width+100)){
        StartingX = -300;
       x = random(0,4); 
      }
    }

    Parking();
  }

  void Parking() {

    if (Gate.open == true && StartingX >= 1000 && StartingY <= 350 && x <= 3) {
      DisplayCar = false;
      if (CarType > 0 && CarType <= 1)
        image(LancerDown, 1000, StartingY, 150, 175);
      else if (CarType > 1 && CarType <= 2)
        image(BMWDown, 1000, StartingY, 150, 200);
      else
        image(PontiacDown, 1000, StartingY, 150, 175);

      StartingY += CarSpeed;
    }

    while (StartingY == 340) {
      ControlPanel.Customers += 1;
      Gate.numberofspots -= 1;
      break;
    }

    if (StartingY >= 350) {
      ChooseStall();
      MinutesStayed += 1;
      if (Leave != 400)
        Leave = (int) random(0, 800);
    }

    LeaveParking();
  }

  void ChooseStall() {
    if (PL.PSS[a][b].PStall[c][d].occupied == false && x <= 3 && CarInStall == true) {
      PL.PSS[a][b].PStall[c][d].occupied = true;
      PL.PSS[a][b].PStall[c][d].drawStall();
    } else if (PL.PSS[a][b].PStall[c][d].occupied == true && x <= 3) {
      while (PL.PSS[a][b].PStall[c][d].occupied == true && a <= 3 && b <= 4 && c <= 6 && d <= 3) {
        a += 1;
        b += 1;
        c += 1;
        d += 1;

        if (a == 2)
          a = 0;

        if (b == 3)
          b = 0;

        if (c == 5)
          c = 0;

        if (d == 2)
          d = 0;
      }
    }
  }

  void LeaveParking() {
    if (Leave == 400) {
      CarInStall = false;
      PL.PSS[a][b].PStall[c][d].occupied = false;

      if (LeavingY <= 1230) {
        if (CarType > 0 && CarType <= 1)
          image(LancerDown, 1000, LeavingY, 150, 175);
        else if (CarType > 1 && CarType <= 2)
          image(BMWDown, 1000, LeavingY, 150, 200);
        else
          image(PontiacDown, 1000, LeavingY, 150, 175);

        LeavingY += CarSpeed;
      }

      if (LeavingY >= 1230) {
        if (CarType > 0 && CarType <= 1) {
          image(Lancer, StartingX, LeavingY, 175, 150);
          StartingX += CarSpeed;
        } else if (CarType > 1 && CarType <= 2) {
          image(BMW, StartingX, LeavingY, 200, 150);
          StartingX += CarSpeed;
        } else {
          image(Pontiac, StartingX, LeavingY, 175, 150);
          StartingX += CarSpeed;
        }
      }

      float fee = (PriceCalculator.CalculatePrice((MinutesStayed/60)));

      while (LeavingY == 1000) {
        Gate.numberofspots += 1;
        ControlPanel.NetProfit += fee;
        Gate.fee = fee;
        break;
      }

      if (StartingX >= (width+100)) {
        Leave = 0;
        StartingX = -300;
        StartingY = 200;
        LeavingY = 900;
        DisplayCar = true;
        CarInStall = true;
        x = random(0,4);
        a = (int) random(0, 2); 
        b = (int) random(0, 3); 
        c = (int) random(0, 5);
        d = (int) random(0, 2);
        MinutesStayed = 0;
        drawCar();
      }
    }
  }
}
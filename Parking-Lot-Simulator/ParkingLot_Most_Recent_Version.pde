ParkingLot PL = new ParkingLot(250, 350, 1700, 900);
Street NorthStreet = new Street(230, "North");
Street SouthStreet = new Street(1270, "South");
Gate Gate = new Gate(true, 0, 60);
Date Date = new Date(0, 0, 0, true);
PriceCalculator PriceCalculator = new PriceCalculator();
ControlPanel ControlPanel = new ControlPanel();
Car [] Car = new Car[20];


//Car Car = new Car(random(0, 3), -100, true);
PImage Lancer;
PImage BMW; 
PImage Pontiac; 
PImage Sun; 
PImage Moon; 
PImage LancerDown;
PImage BMWDown;
PImage PontiacDown;

void setup() {
  size(2200, 1600);
  Lancer =  loadImage("Lancer Evo cut out.png"); 
  BMW = loadImage("BMW M3 Cut out.png");
  Pontiac = loadImage("Pontiac G5.png");
  Sun = loadImage("Sun.png");
  Moon = loadImage("moon.png");
  LancerDown = loadImage("Lancer Evo cut out Facing Down.png");
  BMWDown = loadImage("BMW M3 Cut out Facing Down.png");
  PontiacDown = loadImage("Pontiac G5 Facing Down.png");

  for (int i = 0, x = -100; i < 20; i++, x -= (int)random(800, 1200)) {
    Car[i] = new Car(random(0, 3), x, true);
  }
}

void draw() {
  Date.Daylight();
  PL.drawLot();
  NorthStreet.drawStreet();
  SouthStreet.drawStreet();
  Gate.drawGate();
  Date.addMinute();
  ControlPanel.DateTimeDisplay();
  ControlPanel.ParkingRatesDisplay();
  ControlPanel.PausePlayDisplay();
  ControlPanel.SimulationValuesDisplay();
  for (int i = 0; i < 20; i++) {
    Car[i].drawCar();
  }
}
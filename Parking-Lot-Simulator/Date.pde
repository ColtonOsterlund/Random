class Date
{
  final String [] days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
  int today;
  int hour;
  int minute;
  boolean before_noon;
  String date;

  Date(int d, int h, int m, boolean beforeNoon)
  {
    today = d % 6;
    hour = h % 12;
    if (hour == 0)
      hour = 12;
    minute = m % 60;
    before_noon = beforeNoon;
  }

  Date(Date d) 
  { 
    today = d.today; 
    hour = d.hour; 
    minute = d.minute; 
    before_noon = d.before_noon;
  }

  void addDay() {
    today += 1;
    if (today > 6)
      today -= 7;
  }

  void addHour()
  {
    hour += 1;
    ControlPanel.TimeElapsed += 1;
    if (hour == 13)
      hour = 1;
    if (hour == 12) {
      if (before_noon == true)
        before_noon = false;
      else if (before_noon == false) {
        before_noon = true;
        addDay();
      }
    }
  }

  void addMinute()
  {
    minute += 1;
    if (minute == 60) {
      addHour();
      minute = 0;
    }
  }

  void printDate(int xpos, int ypos, int textsize)
  {
    date = days[today];

    //Format Hour
    if (hour < 10)
      date += " 0" + hour;
    else
      date += " " + hour;

    //Format Minute
    if (minute < 10)
      date += ":0" + minute;
    else
      date += ":" + minute;

    //Format Time of Day
    if (before_noon)
      date += "AM";
    else
      date += "PM";

    fill(255);
    textSize(textsize);
    textAlign(RIGHT);
    text(date, xpos, ypos);
    textAlign(LEFT);
  }

  void Daylight() {
    if ((hour >= 7 && hour < 12 && before_noon == true) || ((hour <= 6 || hour == 12) && before_noon == false)) {
      background(0, 255, 0);
    } else {
      background(0, 50, 0);
    }
  }
}
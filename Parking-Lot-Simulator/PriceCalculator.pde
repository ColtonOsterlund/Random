class PriceCalculator {
  float priceperhour;
  float hoursstayed;


  float CalculatePrice(float hs) {
    hoursstayed = hs;
    if (Date.today >= 0 && Date.today <= 5)
      priceperhour = 3.00;
    else
      priceperhour = 1.50;
    float fee = priceperhour * hoursstayed;
    return fee;
  }
}
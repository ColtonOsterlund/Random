import java.util.ArrayList;

public class Membership
{

  private Date renewalDate;
  private Boolean trainingRoomAccess;
  private Boolean poolAccess;
  private float pricePerMonth;
  private ArrayList<BillingReport> recieptList;

  public Date getRenewalDate(){
    return renewalDate;
  }

  public void setRenewalDate(Date d){
    renewalDate = d;
  }

  public Boolean getTrainingRoomAccess(){
    return trainingRoomAccess;
  }

  public void setTrainingRoomAccess(Boolean b){
    trainingRoomAccess = b;
  }

  public Boolean getPoolAccess(){
    return poolAccess;
  }

  public void setPoolAccess(Boolean b){
    poolAccess = b;
  }

  public float getPricePerMonth(){
    return pricePerMonth;
  }

  public void setPricePerMonth(float f){
    pricePerMonth = f;
  }

  public ArrayList<BillingReport> getRecieptList(){
    return recieptList;
  }

  public BillingReport getReciept(){
    return recieptList.get(i);
  }

  public void addRecieptToList(BillingReport r){
    recieptList.add(r);
  }

}

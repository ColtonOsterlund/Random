public class Person{

  private String emergencyContactNo;
  private int personGymID;
  private String phone;
  private String street;
  private String city;
  private String province;
  private String postal;

  public String getEmergencyContactPhone(){
    return emergencyContactNo;
  }

  public void setEmergencyContactPhone(String s){
    emergencyContactNo = s;
  }

  public int getPersonGymID(){
    return personGymID;
  }

  public void setPersonGymID(int i){
    personGymID = i;
  }

  public String getPhone(){
    return phone;
  }

  public void setPhone(String p){
    phone = p;
  }

  public String getStreet(){
    return street;
  }

  public void setStreet(String s){
    street = s;
  }

  public String getCity(){
    return city;
  }

  public void setCity(String c){
    city = c;
  }

  public String getProvince(){
    return province;
  }

  public void setProvince(String p){
    province = p;
  }

  public String getPostal(){
    return postal;
  }

  public void setPostal(String p){
    postal = p;
  }

}

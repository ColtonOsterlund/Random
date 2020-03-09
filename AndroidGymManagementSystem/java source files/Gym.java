import java.util.ArrayList;

public class Gym {

    public String name;
    public int gymID;
    public String phone;
    public String street;
    public String city;
    public String province;
    public String postal;

    private ArrayList<Person> memberList; //maybe think of a better name? This contains all members and trainers
    private ArrayList<Reservable> equipmentList; //contains all equipment, accessories and rooms

    public ArrayList<Perosn> getMemberList(){
        return memberList;
    }

    public Person getMember(int i){
        return memberList.get(i);
    }

    public ArrayList<Reservable> getEquipmentList(){
        return equipmentList;
    }

    public Reservable getEquipment(int i){
        return equipmentList.get(i);
    }

    public void addPersonToList(Person p){
        memberList.add(p);
    }

    public void addEquipmentToList(Reservable r){
        equipmentList.add(r);
    }
}

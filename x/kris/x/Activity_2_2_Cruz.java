class Car {
  private int model;
  private String name;
  private String color;

  public Car() {}

  public Car(int model,String name,String color) {
    this.model=model;
    this.name=name;
    this.color=color;
  }

  int getModel() {
    return this.model;
  }

  void setModel(int model) {
    this.model=model;
  }

  String getName() {
    return this.name;
  }

  void setName(String name) {
    this.name=name;
  }

  String getColor() {
    return this.color;
  }

  void setColor(String color) {
    this.color=color;
  }

}

class Truck extends Car {
  public Truck() {}

  public Truck(int model,String name,String color) {
    super(model,name,color);
  }
}

class Van extends Car {
  public Van() {}

  public Van(int model,String name,String color) {
    super(model,name,color);
  }
}

public class Activity_2_2_Cruz {
  public static void main(String[] args) {

    Truck truck1=new Truck();
    Truck truck2=new Truck();

    truck1.setModel(2000);
    truck1.setName("Truck1");
    truck1.setColor("Red");

    truck2.setModel(2021);
    truck2.setName("Truck2");
    truck2.setColor("Blue");

    System.out.println("Truck1 Model: "+truck1.getModel());
    System.out.println("Truck1 Name: "+truck1.getName());
    System.out.println("Truck1 Color: "+truck1.getColor());

    System.out.println();

    System.out.println("Truck2 Model: "+truck2.getModel());
    System.out.println("Truck2 Name: "+truck2.getName());
    System.out.println("Truck2 Color: "+truck2.getColor());

  }
}

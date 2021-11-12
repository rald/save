class Program {

  int x=143; // di mo maaaccess to sa main kelangan mo ng instance ng Program object

  static int y=341; // pede mo ito i-access kahit walang instance ng Program object

  Program() {
  }

  public static void main(String[] args) {
    // System.out.println(x); // <-- error ito
    System.out.println("y == "+y); // <-- output: 341
    Program p=new Program();
    System.out.println("p.x == "+p.x); // <-- output: 143
  }
}

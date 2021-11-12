import java.util.Scanner;
class Activity5 {
  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    String setOfWord;
    System.out.print("Enter a string: ");
    setOfWord=scanner.nextLine();
    if(setOfWord.equalsIgnoreCase("lower")) {
      System.out.println(setOfWord.toLowerCase());
    } else if(setOfWord.equalsIgnoreCase("upper")) {
      System.out.println(setOfWord.toUpperCase());
    } else if(setOfWord.equalsIgnoreCase("even")) {
      long p=1;
      for(int i=2;i<=20;i+=2) {
        p*=i;
      }
      System.out.println(p);
    } else if(setOfWord.equalsIgnoreCase("odd")) {
      int s=0;
      for(int i=1;i<=19;i+=2) {
        s+=i;
      }
      System.out.println(s);
    } else if(setOfWord.equalsIgnoreCase("replace")) {
      System.out.println(setOfWord.toLowerCase().replace("place","play"));
    } else {
      System.out.println(setOfWord.length());
    }
  }
}

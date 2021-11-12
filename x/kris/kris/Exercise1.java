class Exercise1 {
  public static void main(String[] args) {
    long number=3871081512118L;
    String str=String.valueOf(number);
    str=str.replace("8","0");
    System.out.println(str);
    System.out.println(str.lastIndexOf("1"));
    str=String.join(" ",str.split(""));
    System.out.println(str);
    char[] chars=str.toCharArray();
    for(int i=0;i<chars.length;i++) chars[i]+=1;
    str=new String(chars);
    System.out.println(str);
    str=new StringBuffer(str).reverse().toString();
    System.out.println(str);
  }
}


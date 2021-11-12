class Lotto_1 {
	public static void main(String[] args) {
	  int min=1;
	  int max=58;
    int needed=6;
    int[] a=new int[max-min+1];

    // populate
    for(int i=0;i<max-min+1;i++) a[i]=i+min;

    // shuffle
    for (int i=a.length-1;i>0;i--) {
      int j=(int)Math.floor(Math.random()*(i+1));
      int t=a[i];
      a[i]=a[j];
      a[j]=t;
    }

    // sort
    for(int j=0;j<needed-1;j++) {
      for(int i=j+1;i<needed;i++) {
        if(a[i]<a[j]) {
          int t=a[i];
          a[i]=a[j];
          a[j]=t;
        }
      }
    }

    // print
    String r="Winning Numbers: ";
    for (int i=0;i<needed;i++) {
        if(i!=0) r+=", ";
        r+=a[i];
    }
    System.out.println(r);

  }
}

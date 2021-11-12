import java.util.Arrays;

class Lotto_2 {
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

    // transfer
    int[] b=new int[needed];
    for(int i=0;i<needed;i++) b[i]=a[i];

    // sort
    Arrays.sort(b);

    // print
    String r="Winning Numbers: ";
    for (int i=0;i<needed;i++) {
        if(i!=0) r+=", ";
        r+=b[i];
    }
    System.out.println(r);

  }
}


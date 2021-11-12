import java.util.Arrays;
class Lotto_0 {
	public static void main(String[] args) {
	  int min=1;
	  int max=58;
    int needed=6;
    int remaining=max-min+1;
    boolean first=true;
		String result="Winning Numbers: ";
		for(int i=min;i<=max;i++) {
      if(((double)needed/remaining)>Math.random()) {
        if(first) first=false; else result+=", ";
        result+=i;
        needed--;
      }
      remaining--;
		}
		System.out.println(result);
	}
}

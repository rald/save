import javax.swing.JFrame;
import java.awt.Graphics;
import java.awt.Color;

class Main extends JFrame implements Runnable {

  int w=640,h=480;
  int x=w/2,y=h/2;

  Main() {
    setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    setSize(640,480);
    setVisible(true);
    Thread thread=new Thread(this);
    thread.start();
  }

  public void paint(Graphics g) {
    g.setColor(Color.BLACK);
    g.drawLine(0,0,639,479);
    g.drawLine(639,0,0,479);
  }

  public void run() {
    while()
  }

  public static void main(String[] args) {
    new Main();
  }

}

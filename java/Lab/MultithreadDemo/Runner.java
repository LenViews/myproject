public class Runner extends Thread {
private RaceTrack track;
private int progress = 0;
private int speed;
public Runner(RaceTrack track, String name, int speed){
super(name);
this.track = track;
this.speed = speed;
}
public void run() {
while(progress < track.getFinishLine()){
progress += (int) (Math.random() * speed);
if(progress > track.getFinishLine()){
progress = track.getFinishLine();
}
System.out.println(getName() + " has covered " + progress + " meters");
} try {
Thread.sleep(500);
} catch (InterruptedException e){
System.out.println(e);
}
}
}

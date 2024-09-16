public class RaceTrack{
private static final int FINISH_LINE = 100;
public synchronized void reachFinishline(String runnerName){
System.out.println(runnerName + "has crossed the finish line!");
}
public int getFinishLine(){
return FINISH_LINE;
}
}

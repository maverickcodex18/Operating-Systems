import java.util.concurrent.*;

public class producerConsumer {

    static private Semaphore access;

    static class cs {
        public static int size=0;
        public static int filled;
        public cs(final int size){
            this.size=size;
        }
    }

    static class producer implements Runnable{

        private void produce(){
            ++cs.filled;
        }

        @Override
        public void run() {
            // TODO Auto-generated method stub
            if (cs.filled==0){
                try{
                    access.acquire();
                    produce();
                    access.release();
                }catch(Throwable t){
                    System.out.println(t);
                }
            }
            else produce();

        }

    }
    public static void main(String args[]){
        access=new Semaphore(1);
    }
}

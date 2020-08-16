public class Hot {
	static { System.out.println("Loading ..."); }
    public void hot(){
        System.out.println(" version 3 : "+this.getClass().getClassLoader());
    }
}
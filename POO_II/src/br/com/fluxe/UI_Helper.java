package br.com.fluxe;

public class UI_Helper {

	public static void showLogo() {
		System.out.println("  ______   _                       \n" + 
				" |  ____| | |                      \n" + 
				" | |__    | |  _   _  __  __   ___ \n" + 
				" |  __|   | | | | | | \\ \\/ /  / _ \\\n" + 
				" | |      | | | |_| |  >  <  |  __/\n" + 
				" |_|      |_|  \\__,_| /_/\\_\\  \\___|\n" + 
				"                                   \n" + 
				"                                   ");
	}
	
	
	public final static void clearConsole()
	{
		System.out.print("\033[H\033[2J");
		System.out.flush();
	    try
	    {
	        final String os = System.getProperty("os.name");

	        if (os.contains("Windows"))
	        {
	            Runtime.getRuntime().exec("cls");
	        }
	        else
	        {
	            Runtime.getRuntime().exec("clear");
	        }
	    }
	    catch (final Exception e)
	    {
	    	System.out.println(e);
	    }
	}
}

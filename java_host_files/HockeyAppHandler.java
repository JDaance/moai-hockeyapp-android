import net.hockeyapp.android.Constants;
import net.hockeyapp.android.CrashManager;
import net.hockeyapp.android.NativeCrashManager;
import android.app.Activity;

public class HockeyAppHandler {

	private static final String HOCKEYAPP_ID = "YOUR_ID";
	private Activity activity;

	private native void setUpNative(String filePath);
	private native void nativeCrash(); 

	public HockeyAppHandler(Activity activity) {
		this.activity = activity;
	}
	
	public void init() {
	    // Handle NDK crashes
	    Constants.loadFromContext(this.activity);
	    setUpNative(Constants.FILES_PATH);
	    NativeCrashManager.handleDumpFiles(this.activity, HOCKEYAPP_ID);
	}

	public void checkForCrashes() {
	    CrashManager.register(this.activity, HOCKEYAPP_ID);
	}

}

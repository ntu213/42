
import datetime as dt

def ft():

	now = dt.datetime.now()
	ts = now.timestamp()

	print("Seconds since January 1, 1970:", "{:,}".format(round(ts, 4)), "or", format(ts, ".2e"), "in scientific notation")
	print(now.strftime("%b %d %Y"))

ft()

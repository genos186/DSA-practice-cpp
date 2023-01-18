import logging

def printer():
    print("This is a test of the logging module. ")

if __name__=="__main__":
    logging.basicConfig(
        filename="trial.log",
        level=logging.DEBUG,
        format="%(asctime)s:%(levelname)s:%(message)s"
    )
    logging.debug("This is a debug message")
    logging.info("This is an info message")
    logging.warning("This is a warning message")
    logging.error("This is an error message")
    logging.critical("This is a critical message")
    printer()
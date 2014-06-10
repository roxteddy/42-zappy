import inspect

def log(message):
    (frame, filename, line_number,function_name, lines, index) = inspect.getouterframes(inspect.currentframe())[1]
    print '%s:%d %s(): %s' % (filename, line_number, function_name, message)

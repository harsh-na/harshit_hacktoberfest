import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
        title: 'Flutter Demo',
        theme: ThemeData(
          primarySwatch: Colors.blue,
        ),
        home: const HomePage());
  }
}

class HomePage extends StatelessWidget {
  const HomePage({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("Bottom Sheet Example"),
      ),
      body: SizedBox(
        width: double.infinity,
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            ElevatedButton(
              onPressed: () {
                showModalBottomSheet(
                  enableDrag: true,
                  shape: RoundedRectangleBorder(
                    borderRadius: BorderRadius.circular(20),
                  ),
                  context: context,
                  builder: (context) {
                    return Column(
                      mainAxisAlignment: MainAxisAlignment.center,
                      children: const [
                        Text("This is Android style bottom sheet")
                      ],
                    );
                  },
                );
              },
              child: Column(
                mainAxisSize: MainAxisSize.min,
                children: const [
                  Text("Open Bottom Sheet"),
                  Text(
                    "Android Style",
                    style: TextStyle(fontSize: 10),
                  ),
                ],
              ),
            ),
            ElevatedButton(
              onPressed: () {
                showCupertinoModalPopup(
                  context: context,
                  builder: (context) {
                    return CupertinoActionSheet(
                      title: const Text("This is title"),
                      message: const Text("This is message"),
                      actions: [
                        CupertinoActionSheetAction(
                          onPressed: () {},
                          child: const Text("This is action 1"),
                        ),
                        CupertinoActionSheetAction(
                          onPressed: () {},
                          child: const Text("This is action 2"),
                        ),
                        CupertinoActionSheetAction(
                          onPressed: () {},
                          child: const Text("This is action 3"),
                        ),
                        CupertinoActionSheetAction(
                          onPressed: () {},
                          child: const Text("This is action 4"),
                        ),
                      ],
                      cancelButton: CupertinoActionSheetAction(
                        onPressed: () {
                          Navigator.pop(context);
                        },
                        child: const Text("Cancel"),
                      ),
                    );
                  },
                );
              },
              child: Column(
                mainAxisSize: MainAxisSize.min,
                children: const [
                  Text("Open Bottom Sheet"),
                  Text(
                    "Ios Style",
                    style: TextStyle(fontSize: 10),
                  ),
                ],
              ),
            ),
          ],
        ),
      ),
    );
  }
}

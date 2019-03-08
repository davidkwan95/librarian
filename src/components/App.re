let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self =>
    <div className="container my-5">
      <Header title="Book Finder" />
      <SearchContainer />
    </div>,
};
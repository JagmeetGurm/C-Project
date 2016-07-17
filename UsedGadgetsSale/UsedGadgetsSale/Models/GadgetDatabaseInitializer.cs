using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data.Entity;
namespace UsedGadgetsSale.Models
{
    public class GadgetDatabaseInitializer
   : DropCreateDatabaseIfModelChanges<GadgetContext>
    {
        protected override void Seed(GadgetContext context)
        {
            GetCategories().ForEach(c => context.Categories.Add(c));
            GetGadgets().ForEach(p => context.Gadgets.Add(p));
        }

        private static List<Category> GetCategories()
        {
            var categories = new List<Category> {
                new Category
                {
                    CategoryID = 1,
                    CategoryName = "CellPhones"
                },
                new Category
                {
                    CategoryID = 2,
                    CategoryName = "TV"
                },
                new Category
                {
                    CategoryID = 3,
                    CategoryName = "Laptops"
                },
                new Category
                {
                    CategoryID = 4,
                    CategoryName = "Cameras"
                },
                
            };

            return categories;
        }

        private static List<Gadget> GetGadgets()
        {
            var gadgets = new List<Gadget> {
                new Gadget
                {
                    GadgetID = 1,
                    GadgetName = "Flip Phone",
                    Description = "It's a flip phone which opens upon flipping." +
                                  "Power it up and let it go!",
                    ImagePath="carconvert.png",
                    UnitPrice = 22.50,
                    CategoryID = 1
               },
                new Gadget
                {
                    GadgetID = 2,
                    GadgetName = "Touch-screen phone",
                    Description = "use the phone by touching the screen with your fingers.",
                    ImagePath="carearly.png",
                    UnitPrice = 15.95,
                     CategoryID = 1
               },
                new Gadget
                {
                    GadgetID = 3,
                    GadgetName = "Nixon Camera",
                    Description = "12 Mpx nixon camera with recorder.",
                    ImagePath="carfast.png",
                    UnitPrice = 32.99,
                    CategoryID = 1
                },
                new Gadget
                {
                    GadgetID = 4,
                    GadgetName = "Sony Camera",
                    Description = "Sony's 14 Mpx camera with image stablizer",
                    ImagePath="carfaster.png",
                    UnitPrice = 8.95,
                    CategoryID = 1
                },
                new Gadget
                {
                    GadgetID = 5,
                    GadgetName = "Old Style Racer",
                    Description = "This old style racer can fly (with user assistance). Gravity controls flight duration." +
                                  "No batteries required.",
                    ImagePath="carracer.png",
                    UnitPrice = 34.95,
                    CategoryID = 1
                },
                new Gadget
                {
                    GadgetID = 6,
                    GadgetName = "Ace Plane",
                    Description = "Authentic airplane toy. Features realistic color and details.",
                    ImagePath="planeace.png",
                    UnitPrice = 95.00,
                    CategoryID = 2
                },
                new Gadget
                {
                    GadgetID = 7,
                    GadgetName = "Glider",
                    Description = "This fun glider is made from real balsa wood. Some assembly required.",
                    ImagePath="planeglider.png",
                    UnitPrice = 4.95,
                    CategoryID = 2
                },
                new Gadget
                {
                    GadgetID = 8,
                    GadgetName = "Paper Plane",
                    Description = "This paper plane is like no other paper plane. Some folding required.",
                    ImagePath="planepaper.png",
                    UnitPrice = 2.95,
                    CategoryID = 2
                },
                new Gadget
                {
                    GadgetID = 9,
                    GadgetName = "Propeller Plane",
                    Description = "Rubber band powered plane features two wheels.",
                    ImagePath="planeprop.png",
                    UnitPrice = 32.95,
                    CategoryID = 2
                },
                new Gadget
                {
                    GadgetID = 10,
                    GadgetName = "Early Truck",
                    Description = "This toy truck has a real gas powered engine. Requires regular tune ups.",
                    ImagePath="truckearly.png",
                    UnitPrice = 15.00,
                    CategoryID = 3
                },
                new Gadget
                {
                    GadgetID = 11,
                    GadgetName = "Fire Truck",
                    Description = "You will have endless fun with this one quarter sized fire truck.",
                    ImagePath="truckfire.png",
                    UnitPrice = 26.00,
                    CategoryID = 3
                },
                new Gadget
                {
                    GadgetID = 12,
                    GadgetName = "Big Truck",
                    Description = "This fun toy truck can be used to tow other trucks that are not as big.",
                    ImagePath="truckbig.png",
                    UnitPrice = 29.00,
                    CategoryID = 3
                },
                new Gadget
                {
                    GadgetID = 13,
                    GadgetName = "Big Ship",
                    Description = "Is it a boat or a ship. Let this floating vehicle decide by using its " +
                                  "artifically intelligent computer brain!",
                    ImagePath="boatbig.png",
                    UnitPrice = 95.00,
                    CategoryID = 4
                },
                new Gadget
                {
                    GadgetID = 14,
                    GadgetName = "Paper Boat",
                    Description = "Floating fun for all! This toy boat can be assembled in seconds. Floats for minutes!" +
                                  "Some folding required.",
                    ImagePath="boatpaper.png",
                    UnitPrice = 4.95,
                    CategoryID = 4
                },
                new Gadget
                {
                    GadgetID = 15,
                    GadgetName = "Sail Boat",
                    Description = "Put this fun toy sail boat in the water and let it go!",
                    ImagePath="boatsail.png",
                    UnitPrice = 42.95,
                    CategoryID = 4
                },
                new Gadget
                {
                    GadgetID = 16,
                    GadgetName = "Rocket",
                    Description = "This fun rocket will travel up to a height of 200 feet.",
                    ImagePath="rocket.png",
                    UnitPrice = 122.95,
                    CategoryID = 5
                }
            };

            return Gadgets;
        }
    }
}